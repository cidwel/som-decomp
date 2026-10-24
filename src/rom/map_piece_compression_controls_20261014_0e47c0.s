.setcpu "65816"
.segment "CODE"
.org $47C0
map_control_0e47c0:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
