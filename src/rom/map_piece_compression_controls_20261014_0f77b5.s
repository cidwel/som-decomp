.setcpu "65816"
.segment "CODE"
.org $77B5
map_control_0f77b5:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count
