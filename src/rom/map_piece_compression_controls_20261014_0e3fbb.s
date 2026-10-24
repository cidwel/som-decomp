.setcpu "65816"
.segment "CODE"
.org $3FBB
map_control_0e3fbb:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
