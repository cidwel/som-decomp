.setcpu "65816"
.segment "CODE"
.org $5E4E
map_control_0c5e4e:
    .byte $F2 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $8B ; distance low bit/count
