.setcpu "65816"
.segment "CODE"
.org $B33C
map_control_0fb33c:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
