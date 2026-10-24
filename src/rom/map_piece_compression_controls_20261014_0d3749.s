.setcpu "65816"
.segment "CODE"
.org $3749
map_control_0d3749:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
    .byte $E3 ; previous-row copy count
