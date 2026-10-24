.setcpu "65816"
.segment "CODE"
.org $32AF
map_control_0f32af:
    .byte $E5 ; previous-row copy count
