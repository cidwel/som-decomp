.setcpu "65816"
.segment "CODE"
.org $32EC
map_control_0f32ec:
    .byte $E7 ; previous-row copy count
