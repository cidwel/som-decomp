.setcpu "65816"
.segment "CODE"
.org $8F32
map_control_0f8f32:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
