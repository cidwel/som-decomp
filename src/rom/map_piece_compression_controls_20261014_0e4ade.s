.setcpu "65816"
.segment "CODE"
.org $4ADE
map_control_0e4ade:
    .byte $EB ; backreference distance high bits
    .byte $93 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
