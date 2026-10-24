.setcpu "65816"
.segment "CODE"
.org $223A
map_control_0f223a:
    .byte $EA ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
