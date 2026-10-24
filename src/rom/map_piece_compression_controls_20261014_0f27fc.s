.setcpu "65816"
.segment "CODE"
.org $27FC
map_control_0f27fc:
    .byte $E1 ; previous-row copy count
