class OhosGLPlatform : public glu::Platform
{
public:
    void registerFactory (de::MovePtr<glu::ContextFactory> factory)
    {
        m_contextFactoryRegistry.registerFactory(factory.release());
    }
};
