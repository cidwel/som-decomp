.setcpu "65816"
.segment "CODE"
.org $6ECD
map_control_0e6ecd:
    .byte $E4 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
