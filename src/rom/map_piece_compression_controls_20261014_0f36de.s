.setcpu "65816"
.segment "CODE"
.org $36DE
map_control_0f36de:
    .byte $E5 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
