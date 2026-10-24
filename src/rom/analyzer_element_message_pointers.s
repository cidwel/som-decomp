; Analyzer element-bit indexed message addresses. No text payload.
.setcpu "65816"
.segment "RODATA"
.org $5DDB
analyzer_element_message_pointers:
    .word $61DA ; C0 message address for weakness mask $01
    .word $61E8 ; C0 message address for weakness mask $02
    .word $61F8 ; C0 message address for weakness mask $04
    .word $6207 ; C0 message address for weakness mask $08
    .word $6219 ; C0 message address for weakness mask $10
    .word $6227 ; C0 message address for weakness mask $20
    .word $6236 ; C0 message address for weakness mask $40
    .word $6243 ; C0 message address for weakness mask $80
