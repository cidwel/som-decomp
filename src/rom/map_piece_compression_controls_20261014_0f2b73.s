.setcpu "65816"
.segment "CODE"
.org $2B73
map_control_0f2b73:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
    .byte $E3 ; previous-row copy count
