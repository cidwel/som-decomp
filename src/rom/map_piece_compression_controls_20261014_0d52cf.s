.setcpu "65816"
.segment "CODE"
.org $52CF
map_control_0d52cf:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
