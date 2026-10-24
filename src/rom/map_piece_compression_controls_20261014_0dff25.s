.setcpu "65816"
.segment "CODE"
.org $FF25
map_control_0dff25:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $C5 ; same-value copy count/distance
