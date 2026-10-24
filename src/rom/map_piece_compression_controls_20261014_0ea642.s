.setcpu "65816"
.segment "CODE"
.org $A642
map_control_0ea642:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
