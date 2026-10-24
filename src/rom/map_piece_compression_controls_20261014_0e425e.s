.setcpu "65816"
.segment "CODE"
.org $425E
map_control_0e425e:
    .byte $EB ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
