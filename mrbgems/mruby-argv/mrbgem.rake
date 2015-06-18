MRuby::Gem::Specification.new('mruby-argv') do |spec|
  spec.license = 'MIT'
  spec.author  = 'mruby developers'
  spec.summary = 'expose argv arguments to mruby binary'

  build.cc.include_paths << "#{build.root}/mrbgems/mruby-argv/include/"
end
