.setcpu "65816"
.segment "CODE"
.org $46DF
map_control_0c46df:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
