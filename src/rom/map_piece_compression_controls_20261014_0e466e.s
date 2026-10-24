.setcpu "65816"
.segment "CODE"
.org $466E
map_control_0e466e:
    .byte $EB ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
