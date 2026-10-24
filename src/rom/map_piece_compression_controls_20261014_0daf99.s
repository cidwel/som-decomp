.setcpu "65816"
.segment "CODE"
.org $AF99
map_control_0daf99:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E1 ; previous-row copy count
