.setcpu "65816"
.segment "CODE"
.org $BBEA
map_control_0dbbea:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
