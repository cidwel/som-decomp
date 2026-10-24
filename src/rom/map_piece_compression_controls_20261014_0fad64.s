.setcpu "65816"
.segment "CODE"
.org $AD64
map_control_0fad64:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
