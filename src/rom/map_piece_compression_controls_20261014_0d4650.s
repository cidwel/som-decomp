.setcpu "65816"
.segment "CODE"
.org $4650
map_control_0d4650:
    .byte $F0 ; progressive-copy escape
    .byte $82 ; direction/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
