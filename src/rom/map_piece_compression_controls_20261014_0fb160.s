.setcpu "65816"
.segment "CODE"
.org $B160
map_control_0fb160:
    .byte $E5 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
