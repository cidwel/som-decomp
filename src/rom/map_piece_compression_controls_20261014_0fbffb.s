.setcpu "65816"
.segment "CODE"
.org $BFFB
map_control_0fbffb:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
