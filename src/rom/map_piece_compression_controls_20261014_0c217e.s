.setcpu "65816"
.segment "CODE"
.org $217E
map_control_0c217e:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
