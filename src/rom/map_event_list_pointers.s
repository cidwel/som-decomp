; Typed map structure; docs/map-structural-index-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4000
map_event_list_pointers:
    ; Map IDs $000..$007; bank C8 is supplied by the consumer.
    .word $4400, $4400, $4400, $4402, $4402, $4404, $4406, $4406
    ; Map IDs $008..$00F; bank C8 is supplied by the consumer.
    .word $4406, $4408, $4408, $4408, $4408, $4408, $4408, $4408
    ; Map IDs $010..$017; bank C8 is supplied by the consumer.
    .word $440A, $4428, $4438, $4442, $4450, $4482, $4498, $44A4
    ; Map IDs $018..$01F; bank C8 is supplied by the consumer.
    .word $44B4, $44BA, $44CE, $44D6, $44EE, $44F4, $44FA, $4508
    ; Map IDs $020..$027; bank C8 is supplied by the consumer.
    .word $450E, $451A, $451A, $451A, $451E, $452E, $4552, $4552
    ; Map IDs $028..$02F; bank C8 is supplied by the consumer.
    .word $4560, $456E, $4578, $45A8, $45D2, $45D6, $45DA, $45DE
    ; Map IDs $030..$037; bank C8 is supplied by the consumer.
    .word $45E8, $45F0, $45FC, $45FC, $4600, $4618, $4630, $463C
    ; Map IDs $038..$03F; bank C8 is supplied by the consumer.
    .word $4648, $465E, $4666, $466E, $4678, $468C, $469A, $46A4
    ; Map IDs $040..$047; bank C8 is supplied by the consumer.
    .word $46B8, $46CA, $46D2, $46E2, $46F6, $4710, $4724, $4732
    ; Map IDs $048..$04F; bank C8 is supplied by the consumer.
    .word $4732, $473C, $4756, $4756, $4760, $476E, $4778, $477E
    ; Map IDs $050..$057; bank C8 is supplied by the consumer.
    .word $477E, $4786, $4798, $47B0, $47BA, $47C2, $47DC, $47F0
    ; Map IDs $058..$05F; bank C8 is supplied by the consumer.
    .word $480A, $4824, $4836, $4840, $4840, $4854, $4862, $4876
    ; Map IDs $060..$067; bank C8 is supplied by the consumer.
    .word $488A, $489A, $48AE, $48C6, $48DE, $48DE, $48DE, $48DE
    ; Map IDs $068..$06F; bank C8 is supplied by the consumer.
    .word $48DE, $48DE, $48DE, $48DE, $48DE, $48DE, $48EA, $48EE
    ; Map IDs $070..$077; bank C8 is supplied by the consumer.
    .word $48F6, $48FC, $4912, $4922, $4946, $4956, $496C, $4984
    ; Map IDs $078..$07F; bank C8 is supplied by the consumer.
    .word $498C, $4990, $4994, $49AC, $49D6, $49FE, $4A24, $4A3C
    ; Map IDs $080..$087; bank C8 is supplied by the consumer.
    .word $4A66, $4A6E, $4A78, $4A80, $4A94, $4A9A, $4A9A, $4A9C
    ; Map IDs $088..$08F; bank C8 is supplied by the consumer.
    .word $4AA4, $4AB2, $4ABA, $4AE4, $4AF4, $4AFC, $4AFC, $4B0C
    ; Map IDs $090..$097; bank C8 is supplied by the consumer.
    .word $4B1C, $4B3E, $4B48, $4B48, $4B48, $4B48, $4B48, $4B48
    ; Map IDs $098..$09F; bank C8 is supplied by the consumer.
    .word $4B48, $4B48, $4B48, $4B48, $4B4E, $4B54, $4B5A, $4B62
    ; Map IDs $0A0..$0A7; bank C8 is supplied by the consumer.
    .word $4B68, $4B74, $4B90, $4B9A, $4BA0, $4BA6, $4BA6, $4BAA
    ; Map IDs $0A8..$0AF; bank C8 is supplied by the consumer.
    .word $4BB0, $4BBC, $4BBC, $4BC8, $4BCE, $4BCE, $4BCE, $4BCE
    ; Map IDs $0B0..$0B7; bank C8 is supplied by the consumer.
    .word $4BCE, $4BCE, $4BCE, $4BCE, $4BCE, $4BCE, $4BCE, $4BCE
    ; Map IDs $0B8..$0BF; bank C8 is supplied by the consumer.
    .word $4BCE, $4BCE, $4BCE, $4BCE, $4BCE, $4BCE, $4BCE, $4BCE
    ; Map IDs $0C0..$0C7; bank C8 is supplied by the consumer.
    .word $4BCE, $4BCE, $4BCE, $4BDE, $4BF0, $4BFA, $4C0A, $4C18
    ; Map IDs $0C8..$0CF; bank C8 is supplied by the consumer.
    .word $4C24, $4C2C, $4C38, $4C40, $4C4C, $4C56, $4C62, $4C6A
    ; Map IDs $0D0..$0D7; bank C8 is supplied by the consumer.
    .word $4C72, $4C7A, $4C86, $4C8A, $4C92, $4C9A, $4CA4, $4CAC
    ; Map IDs $0D8..$0DF; bank C8 is supplied by the consumer.
    .word $4CB4, $4CC0, $4CC8, $4CD0, $4CDC, $4CE4, $4CEC, $4CF4
    ; Map IDs $0E0..$0E7; bank C8 is supplied by the consumer.
    .word $4CFC, $4D0E, $4D1A, $4D24, $4D2C, $4D3E, $4D46, $4D4A
    ; Map IDs $0E8..$0EF; bank C8 is supplied by the consumer.
    .word $4D50, $4D5C, $4D6A, $4D78, $4D86, $4D86, $4D8A, $4D8A
    ; Map IDs $0F0..$0F7; bank C8 is supplied by the consumer.
    .word $4D8A, $4D98, $4D98, $4D98, $4D98, $4DB8, $4DBC, $4DC0
    ; Map IDs $0F8..$0FF; bank C8 is supplied by the consumer.
    .word $4DC0, $4DEC, $4DF6, $4DFC, $4E00, $4E00, $4E00, $4E00
    ; Map IDs $100..$107; bank C8 is supplied by the consumer.
    .word $4E06, $4E08, $4E08, $4E10, $4E14, $4E14, $4E1E, $4E22
    ; Map IDs $108..$10F; bank C8 is supplied by the consumer.
    .word $4E28, $4E32, $4E46, $4E4E, $4E52, $4E54, $4E6C, $4E78
    ; Map IDs $110..$117; bank C8 is supplied by the consumer.
    .word $4E7C, $4E7C, $4E80, $4E84, $4E8E, $4E92, $4E9C, $4EA0
    ; Map IDs $118..$11F; bank C8 is supplied by the consumer.
    .word $4EA4, $4EAA, $4EAE, $4EB4, $4EC8, $4EE2, $4F00, $4F16
    ; Map IDs $120..$127; bank C8 is supplied by the consumer.
    .word $4F36, $4F3E, $4F42, $4F42, $4F4C, $4F52, $4F56, $4F5E
    ; Map IDs $128..$12F; bank C8 is supplied by the consumer.
    .word $4F6A, $4F74, $4F7E, $8A00, $8A04, $8A0C, $8A14, $8A22
    ; Map IDs $130..$137; bank C8 is supplied by the consumer.
    .word $8A30, $8A38, $8A3E, $8A48, $8A48, $8A4E, $8A54, $8A58
    ; Map IDs $138..$13F; bank C8 is supplied by the consumer.
    .word $8A5C, $8A82, $8AA8, $8AB8, $8AC0, $8ACA, $8ACE, $8AD4
    ; Map IDs $140..$147; bank C8 is supplied by the consumer.
    .word $8AD8, $8AF6, $8B10, $8B2E, $8B3A, $8B46, $8B4E, $8B5E
    ; Map IDs $148..$14F; bank C8 is supplied by the consumer.
    .word $8B6C, $8B7C, $8B8C, $8BA0, $8BA4, $8BB2, $8BB2, $8BB2
    ; Map IDs $150..$157; bank C8 is supplied by the consumer.
    .word $8BB2, $8BBC, $8BC2, $8BC4, $8BCA, $8BCA, $8BCE, $8BCE
    ; Map IDs $158..$15F; bank C8 is supplied by the consumer.
    .word $8BCE, $8BCE, $8BDE, $8BF2, $8BFC, $8C06, $8C0A, $8C12
    ; Map IDs $160..$167; bank C8 is supplied by the consumer.
    .word $8C16, $8C28, $8C30, $8C38, $8C44, $8C44, $8C4C, $8C54
    ; Map IDs $168..$16F; bank C8 is supplied by the consumer.
    .word $8C5A, $8C68, $8C68, $8C6E, $8C74, $8C74, $8C78, $8C78
    ; Map IDs $170..$177; bank C8 is supplied by the consumer.
    .word $8C82, $8CB0, $8CCC, $8CEC, $8CEC, $8CEC, $8CF4, $8D04
    ; Map IDs $178..$17F; bank C8 is supplied by the consumer.
    .word $8D08, $8D0C, $8D0E, $8D18, $8D20, $8D2A, $8D32, $8D38
    ; Map IDs $180..$187; bank C8 is supplied by the consumer.
    .word $8D38, $8D44, $8D58, $8D5E, $8D64, $8D6C, $8D74, $8D86
    ; Map IDs $188..$18F; bank C8 is supplied by the consumer.
    .word $8D8C, $8D8C, $8D94, $8D9C, $8DA4, $8DAC, $8DAC, $8DAC
    ; Map IDs $190..$197; bank C8 is supplied by the consumer.
    .word $8DAC, $8DCA, $8DE6, $8DF8, $8E1E, $8E2C, $8E3E, $8E56
    ; Map IDs $198..$19F; bank C8 is supplied by the consumer.
    .word $8E5E, $8E5E, $8E6A, $8E72, $8E72, $8E80, $8E8C, $8EB4
    ; Map IDs $1A0..$1A7; bank C8 is supplied by the consumer.
    .word $8EE8, $8EF8, $8F1C, $8F26, $8F2C, $8F2C, $8F2C, $8F2C
    ; Map IDs $1A8..$1AF; bank C8 is supplied by the consumer.
    .word $8F2C, $8F2C, $8F2C, $8F2C, $8F2C, $8F2C, $8F2C, $8F3C
    ; Map IDs $1B0..$1B7; bank C8 is supplied by the consumer.
    .word $8F42, $8F54, $8F60, $8F6A, $8F74, $8F86, $8F86, $8F86
    ; Map IDs $1B8..$1BF; bank C8 is supplied by the consumer.
    .word $8F86, $8F86, $8F86, $8F86, $8F86, $8F8C, $8F94, $8FA2
    ; Map IDs $1C0..$1C7; bank C8 is supplied by the consumer.
    .word $8FA2, $8FA2, $8FA2, $8FA2, $8FA2, $8FA2, $8FA2, $8FA2
    ; Map IDs $1C8..$1CF; bank C8 is supplied by the consumer.
    .word $8FA2, $8FA2, $8FA2, $8FA2, $8FA2, $8FA2, $8FA2, $8FA2
    ; Map IDs $1D0..$1D7; bank C8 is supplied by the consumer.
    .word $8FA2, $8FA2, $8FA2, $8FA2, $8FA2, $8FA2, $8FA2, $8FA2
    ; Map IDs $1D8..$1DF; bank C8 is supplied by the consumer.
    .word $8FA2, $8FA2, $8FA2, $8FA2, $8FA2, $8FA2, $8FA2, $8FA2
    ; Map IDs $1E0..$1E7; bank C8 is supplied by the consumer.
    .word $8FA2, $8FA2, $8FA2, $8FA2, $8FA2, $8FA2, $8FA2, $8FA2
    ; Map IDs $1E8..$1EF; bank C8 is supplied by the consumer.
    .word $8FA2, $8FA2, $8FA2, $8FA2, $8FA2, $8FA2, $8FA2, $8FA2
    ; Map IDs $1F0..$1F7; bank C8 is supplied by the consumer.
    .word $8FA8, $8FA8, $8FA8, $8FA8, $8FA8, $8FA8, $8FA8, $8FA8
    ; Map IDs $1F8..$1FF; bank C8 is supplied by the consumer.
    .word $8FA8, $8FA8, $8FA8, $8FA8, $8FA8, $8FA8, $8FA8, $8FA8
