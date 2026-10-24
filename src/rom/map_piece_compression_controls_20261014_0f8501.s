.setcpu "65816"
.segment "CODE"
.org $8501
map_control_0f8501:
    .byte $E1 ; previous-row copy count
