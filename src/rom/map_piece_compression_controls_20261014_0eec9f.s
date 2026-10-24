.setcpu "65816"
.segment "CODE"
.org $EC9F
map_control_0eec9f:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
