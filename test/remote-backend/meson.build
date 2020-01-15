supervisord = find_program('supervisord')
supervisorctl = find_program('supervisorctl')
sysrepoctl = find_program('sysrepoctl')
sysrepocfg = find_program('sysrepocfg')
nosetests = find_program('nosetests')
run_remote_backend_tests = find_program('run-remote-backend-tests.sh')

supervisord_conf_data = configuration_data()
supervisord_conf_data.set('pdns_sysrepo', pdns_sysrepo_bin.full_path())

supervisord_conf = configure_file(input: 'supervisord.conf.in',
               output: 'supervisord.conf',
               configuration: supervisord_conf_data)

configure_file(input: 'pdns-sysrepo.yaml.in',
               output: 'pdns-sysrepo.yaml',
               copy: true)

remote_backend_test_env = environment()
remote_backend_test_env.set('SUPERVISORD', supervisord.path())
remote_backend_test_env.set('SUPERVISORCTL', supervisorctl.path())
remote_backend_test_env.set('SUPERVISORDCONF', 'test/remote-backend/supervisord.conf')
remote_backend_test_env.set('SYSREPOCTL', sysrepoctl.path())
remote_backend_test_env.set('SYSREPOCFG', sysrepocfg.path())
remote_backend_test_env.set('NOSETESTS', nosetests.path())

remote_backend_test_env.set('SYSREPO_INITIAL_CONFIG', meson.source_root() + '/test/remote-backend/config-initial.json')
remote_backend_test_env.set('TEST_INITIAL_CONFIG_PY', meson.source_root() + '/test/remote-backend/test-initial-config.py')

# For the actual tests we use python, these are the modules we need
python = find_program('python3')
python_required_modules = ['requests']
foreach p : python_required_modules
  # Source: https://docs.python.org/3/library/importlib.html#checking-if-a-module-can-be-imported
  script = 'import importlib.util; import sys; exit(1) if importlib.util.find_spec(\''+ p +'\') is None else exit(0)'
  if run_command(python, '-c', script).returncode() != 0
    error('Required Python module \'' + p + '\' not found')
  endif
endforeach

test('remote-backend end-to-end', run_remote_backend_tests, env: remote_backend_test_env)