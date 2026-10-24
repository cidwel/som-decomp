.setcpu "65816"
.segment "CODE"
.org $AF1A
map_control_0faf1a:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
