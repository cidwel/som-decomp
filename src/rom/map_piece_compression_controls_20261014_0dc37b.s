.setcpu "65816"
.segment "CODE"
.org $C37B
map_control_0dc37b:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
