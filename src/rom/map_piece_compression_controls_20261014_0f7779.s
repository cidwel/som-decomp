.setcpu "65816"
.segment "CODE"
.org $7779
map_control_0f7779:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
