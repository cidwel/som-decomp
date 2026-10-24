.setcpu "65816"
.segment "CODE"
.org $D656
map_control_0ed656:
    .byte $E0 ; previous-row copy escape
    .byte $4E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $3E ; distance low bit/count
