.setcpu "65816"
.segment "CODE"
.org $2EDF
map_control_0f2edf:
    .byte $E1 ; previous-row copy count
