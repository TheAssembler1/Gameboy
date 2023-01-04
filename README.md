# Gameboy Emulator (written in c++)

#### ToDo
1. Mask necessary bits on f register read and writes

#### Docs
- Pandocs: https://gbdev.io/pandocs
- Complete Technical Reference: https://github.com/Gekkio/gb-ctr
- The Cycle-Accurate GB Docs: https://github.com/AntonioND/giibiiadvance/blob/master/docs/TCAGBD.pdf
- Opcode table: https://izik1.github.io/gbops/table/table.html
- List of GB opcodes and their behavior: https://rednex.github.io/rgbds/gbz80.7.html
- GB instruction decoding table: https://cdn.discordapp.com/attachments/465586075830845475/742438340078469150/SM83_decoding.pdf
- Decoding GB opcodes algorithmically: https://gb-archive.github.io/salvage/decoding_gbz80_opcodes/Decoding%20Gamboy%20Z80%20Opcodes.html
- A journey into GB emulation: https://robertovaccari.com/blog/2020_09_26_gameboy
- http://www.codeslinger.co.uk/pages/projects/gameboy.html
- WIP tutorial on writing a GB emulator in Rust: https://rylev.github.io/DMG-01/public/book/
- GameBoy Emulator Development Guide: https://hacktix.github.io/GBEDG
- Test ROMs:
        - Blargg's test ROMs: https://github.com/retrio/gb-test-roms
        - Mooneye-gb test ROMs: https://github.com/Gekkio/mooneye-test-suite
        - dmg-acid (rendering test): https://github.com/mattcurrie/dmg-acid2
        - cgb-acid (rendering test): https://github.com/mattcurrie/cgb-acid2
        - PeterLemon's GB demos: https://github.com/PeterLemon/GB
        - Test ROM execution logs: https://github.com/wheremyfoodat/Gameboy-logs
- Bootrom disassembly: https://gist.github.com/6063288
- The Ultimate Game Boy Talk: https://youtu.be/HyzD8pNlpwI
- Other valuable resources: https://github.com/avivace/awesome-gbdev
- Notes by GhostSonic on GB sound emulation: https://www.reddit.com/r/EmuDev/comments/5gkwi5/gb_apu_sound_emulation/dat3zni
- Explanation of binary-coded decimals and the DAA instruction: https://ehaskins.com/2018-01-30%20Z80%20DAA
- Guide to the half-carry flag: https://robdor.com/2016/08/10/gameboy-emulator-half-carry-flag

#### Dependencies
1. Plog - https://github.com/SergiusTheBest/plog
	- Logging library