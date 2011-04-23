

	} catch (var e) {
		std::cout << "Uncatched error: " << e << std::endl;
	}

#ifdef _WIN32
	system("pause");
#endif
}
