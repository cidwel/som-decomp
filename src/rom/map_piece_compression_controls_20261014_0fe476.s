.setcpu "65816"
.segment "CODE"
.org $E476
map_control_0fe476:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
