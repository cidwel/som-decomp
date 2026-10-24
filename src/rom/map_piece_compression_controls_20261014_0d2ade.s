.setcpu "65816"
.segment "CODE"
.org $2ADE
map_control_0d2ade:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
