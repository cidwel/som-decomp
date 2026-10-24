.setcpu "65816"
.segment "CODE"
.org $99EA
map_control_0f99ea:
    .byte $E2 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
