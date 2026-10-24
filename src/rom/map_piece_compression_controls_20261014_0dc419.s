.setcpu "65816"
.segment "CODE"
.org $C419
map_control_0dc419:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3E ; row-distance/count
