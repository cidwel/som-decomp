.setcpu "65816"
.segment "CODE"
.org $FC32
native_shop_item_list_pointers:
    .word $FC52 ; shop 0
    .word $FC58 ; shop 1
    .word $FC64 ; shop 2
    .word $FC6B ; shop 3
    .word $FC73 ; shop 4
    .word $FC7F ; shop 5
    .word $FC89 ; shop 6
    .word $FC95 ; shop 7
    .word $FC9F ; shop 8
    .word $FCA9 ; shop 9
    .word $FCB3 ; shop 10
    .word $FCC1 ; shop 11
    .word $FCCE ; shop 12
    .word $FCD7 ; shop 13
    .word $FCE3 ; shop 14
    .word $FCF0 ; shop 15
