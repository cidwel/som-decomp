.setcpu "65816"
.segment "CODE"
.org $330B
map_control_0d330b:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
