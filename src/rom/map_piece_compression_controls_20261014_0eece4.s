.setcpu "65816"
.segment "CODE"
.org $ECE4
map_control_0eece4:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
