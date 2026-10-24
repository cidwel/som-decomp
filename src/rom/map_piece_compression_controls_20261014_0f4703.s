.setcpu "65816"
.segment "CODE"
.org $4703
map_control_0f4703:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
