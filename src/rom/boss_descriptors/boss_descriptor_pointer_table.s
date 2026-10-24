; Typed fields consumed by C23438; docs/boss-descriptor-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BC34
boss_descriptor_00_address = $D080
boss_descriptor_01_address = $D658
boss_descriptor_02_address = $D20A
boss_descriptor_03_address = $DF9E
boss_descriptor_04_address = $E5AD
boss_descriptor_05_address = $DD35
boss_descriptor_06_address = $D451
boss_descriptor_07_address = $EB49
boss_descriptor_08_address = $E82E
boss_descriptor_09_address = $E120
boss_descriptor_0a_address = $ECFD
boss_descriptor_0b_address = $F00C
boss_descriptor_0c_address = $DAEA
boss_descriptor_0d_address = $E2F5
boss_descriptor_0e_address = $D8D8
boss_descriptor_pointer_table:
boss_descriptor_pointer_00:
    .word boss_descriptor_00_address
boss_descriptor_pointer_01:
    .word boss_descriptor_01_address
boss_descriptor_pointer_02:
    .word boss_descriptor_02_address
boss_descriptor_pointer_03:
    .word boss_descriptor_03_address
boss_descriptor_pointer_04:
    .word boss_descriptor_04_address
boss_descriptor_pointer_05:
    .word boss_descriptor_05_address
boss_descriptor_pointer_06:
    .word boss_descriptor_06_address
boss_descriptor_pointer_07:
    .word boss_descriptor_07_address
boss_descriptor_pointer_08:
    .word boss_descriptor_08_address
boss_descriptor_pointer_09:
    .word boss_descriptor_09_address
boss_descriptor_pointer_0a:
    .word boss_descriptor_0a_address
boss_descriptor_pointer_0b:
    .word boss_descriptor_0b_address
boss_descriptor_pointer_0c:
    .word boss_descriptor_0c_address
boss_descriptor_pointer_0d:
    .word boss_descriptor_0d_address
boss_descriptor_pointer_0e:
    .word boss_descriptor_0e_address
