.setcpu "65816"
.segment "CODE"
.org $AF42
map_control_0eaf42:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $6E ; row-distance/count
