.setcpu "65816"
.segment "CODE"
.org $0762
map_control_0e0762:
    .byte $F3 ; progressive-copy count
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
