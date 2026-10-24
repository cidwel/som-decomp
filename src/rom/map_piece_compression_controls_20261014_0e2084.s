.setcpu "65816"
.segment "CODE"
.org $2084
map_control_0e2084:
    .byte $E3 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $87 ; distance low bit/count
