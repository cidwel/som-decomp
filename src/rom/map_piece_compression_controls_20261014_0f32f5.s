.setcpu "65816"
.segment "CODE"
.org $32F5
map_control_0f32f5:
    .byte $E3 ; previous-row copy count
