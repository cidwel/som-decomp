.setcpu "65816"
.segment "CODE"
.org $253A
map_control_0d253a:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
