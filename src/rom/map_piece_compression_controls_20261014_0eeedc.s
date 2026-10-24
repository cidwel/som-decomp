.setcpu "65816"
.segment "CODE"
.org $EEDC
map_control_0eeedc:
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
