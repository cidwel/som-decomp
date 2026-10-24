.setcpu "65816"
.segment "CODE"
.org $403C
map_control_0f403c:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $53 ; row-distance/count
