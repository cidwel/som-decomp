.setcpu "65816"
.segment "CODE"
.org $32B8
map_control_0f32b8:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
